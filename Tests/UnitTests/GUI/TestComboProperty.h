#include <QtTest>
#include "ComboProperty.h"

class TestComboProperty : public QObject {
    Q_OBJECT

private slots:
    void test_ComboEquality();
    void test_VariantEquality();
    void test_setValue();
    void test_stringOfValues();
};

inline void TestComboProperty::test_ComboEquality()
{
        ComboProperty c1;
        ComboProperty c2;
        QVERIFY(c1 == c2);

        c1 << "a1" << "a2";
        c2 << "a1" << "a2";
        QVERIFY(c1 == c2);

        c2 << "a3";
        QVERIFY(c1 != c2);
        c2.setValue("a2");
        QVERIFY(c1 != c2);

        c1 << "a3";
        c1.setValue("a2");
        QVERIFY(c1 == c2);
}

inline void TestComboProperty::test_VariantEquality()
{
    QVariant v1(1.0);
    QVariant v2(2.0);
    QVariant v3(2.0);
    QVERIFY(v1 != v2);
    QVERIFY(v2 == v3);

    ComboProperty c1 = ComboProperty() << "a1" << "a2";
    ComboProperty c2 = ComboProperty() << "a1" << "a2";
    QVERIFY(c1.getVariant() == c2.getVariant());

    c2 << "a3";
    QVERIFY(c1.getVariant() != c2.getVariant());
    c2.setValue("a2");
    QVERIFY(c1.getVariant() != c2.getVariant());

    c1 << "a3";
    c1.setValue("a2");
    QVERIFY(c1.getVariant() == c2.getVariant());
}

inline void TestComboProperty::test_setValue()
{
    QStringList expectedValues = QStringList() << "a1" << "a2";
    ComboProperty combo = ComboProperty() << expectedValues;

    QCOMPARE(combo.getValue(), QString("a1"));
}

inline void TestComboProperty::test_stringOfValues()
{
    QStringList expectedValues = QStringList() << "a1" << "a2";
    ComboProperty combo = ComboProperty() << expectedValues;

    QCOMPARE(combo.stringOfValues(), QString("a1;a2"));

    // setting string of values, current value should change
    QString stringOfValues("b1;b2;b3");
    combo.setStringOfValues(stringOfValues);
    QCOMPARE(combo.stringOfValues(), stringOfValues);
    QCOMPARE(combo.getValue(), QString("b1"));

    // setting new string of values, containing current value. Current values should remain.
    stringOfValues = QString("c1;b1;c3");
    combo.setStringOfValues(stringOfValues);
    QCOMPARE(combo.stringOfValues(), stringOfValues);
    QCOMPARE(combo.getValue(), QString("b1"));

}
