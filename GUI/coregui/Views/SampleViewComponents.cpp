#include "SampleViewComponents.h"
#include "widgetbox.h"
#include "SampleEditor.h"


SampleWidgetBoxInterface *SampleViewComponents::createWidgetBox(ISampleEditor *core, QWidget *parent)
{
    QDesignerWidgetBoxInterface *result = new qdesigner_internal::WidgetBox(core, parent);
    result->setFileName(QStringLiteral(":/widgetbox/widgetbox.xml"));
    result->load();
    result->setWindowTitle(QLatin1String("Widget Box"));
    result->setObjectName(QLatin1String("WidgetBox"));
    //m_sampleEditor->setWidgetBox(wb);
    return result;
}


//SamplePropertyEditorInterface *SampleViewComponents::createPropertyEditor(QWidget *parent)
SamplePropertyEditor *SampleViewComponents::createPropertyEditor(QWidget *parent)
{
    //SamplePropertyEditorInterface *result = new SamplePropertyEditorInterface(parent);
    SamplePropertyEditor *result = new SamplePropertyEditor(parent);
    result->setWindowTitle(QLatin1String("Property Editor"));
    result->setObjectName(QLatin1String("PropertyEditor"));
    return result;
}

SampleTreeInspectorInterface *SampleViewComponents::createTreeInspector(QWidget *parent)
{
    return new SampleTreeInspectorInterface(parent);
}

SampleInfoStreamInterface *SampleViewComponents::createInfoStream(QWidget *parent)
{
    return new SampleInfoStreamInterface(parent);
}

