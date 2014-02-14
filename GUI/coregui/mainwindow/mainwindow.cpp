#include "mainwindow.h"
#include "fancytabwidget.h"
#include "manhattanstyle.h"
#include "actionmanager.h"
#include "WelcomeView.h"
#include "SampleView.h"
#include "PyScriptView.h"
#include "InstrumentView.h"
#include "SimulationView.h"
#include "JobView.h"
#include "FitView.h"
#include "stylehelper.h"
#include "SimulationDataModel.h"
#include "Instrument.h"
#include "Units.h"
#include "Samples.h"
#include "InterferenceFunctions.h"
#include "FormFactors.h"
#include "mainwindow_constants.h"
#include "hostosinfo.h"

#include <QApplication>
#include <iostream>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : Manhattan::FancyMainWindow(parent)
    , m_tabWidget(0)
    , m_welcomeView(0)
    , m_instrumentView(0)
    , m_sampleView(0)
    , m_scriptView(0)
    , m_simulationView(0)
    , m_jobView(0)
    , m_fitView(0)
    , m_actionManager(0)
    , mp_sim_data_model(0)
{
    // initialize simulation data model first:
    initSimModel();

    QString baseName = QApplication::style()->objectName();
    qApp->setStyle(new ManhattanStyle(baseName));
    Manhattan::Utils::StyleHelper::setBaseColor(QColor(0x086FA1));

    setDockNestingEnabled(true);

    setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);
    setCorner(Qt::BottomRightCorner, Qt::BottomDockWidgetArea);

    m_tabWidget = new Manhattan::FancyTabWidget();
    m_welcomeView = new WelcomeView();
    m_instrumentView = new InstrumentView(mp_sim_data_model);
    m_sampleView = new SampleView();
    m_scriptView = new PyScriptView(mp_sim_data_model);
    m_simulationView = new SimulationView(mp_sim_data_model);
    m_jobView = new JobView(mp_sim_data_model);
    m_fitView = new FitView();

    m_tabWidget->insertTab(0, m_welcomeView, QIcon(":/images/mode_welcome.png"), "Welcome");
    m_tabWidget->insertTab(1, m_instrumentView, QIcon(":/images/mode_exp.png"), "Instrument");
    m_tabWidget->insertTab(2, m_sampleView, QIcon(":/images/mode_sample.png"), "Sample");
    m_tabWidget->insertTab(3, m_scriptView, QIcon(":/images/mode_script.png"), "Python scripts");
    m_tabWidget->insertTab(4, m_simulationView, QIcon(":/images/mode_simul.png"), "Simulation");
    m_tabWidget->insertTab(5, m_jobView, QIcon(":/images/mode_job.png"), "Jobs");
    m_tabWidget->insertTab(6, m_fitView, QIcon(":/images/mode_fit.png"), "Fit");

    m_tabWidget->setCurrentIndex(2);
    setCentralWidget(m_tabWidget);

    m_actionManager = new ActionManager(this);

    setAcceptDrops(true);

    // signals/slots
    connect(m_tabWidget, SIGNAL(currentChanged(int)), this, SLOT(onChangeTabWidget(int)));
}

MainWindow::~MainWindow()
{
//    delete m_actionManager;
}



void MainWindow::newProject()
{
    std::cout << "XXX newProject() "    << std::endl;
}

void MainWindow::openProject()
{
    std::cout << "XXX openProject() "    << std::endl;
}


void MainWindow::onChangeTabWidget(int index)
{
    // update views which depend on others
    (void)index;
    m_simulationView->updateViewElements();
    if (index==5) {
        m_jobView->updateJobsAndGraphics();
    }
}

void MainWindow::initSimModel()
{
    if (mp_sim_data_model) delete mp_sim_data_model;
    mp_sim_data_model = new SimulationDataModel;
    mp_sim_data_model->addInstrument(tr("Default GISAS"), createDefaultInstrument());
    mp_sim_data_model->addSample(tr("Default cylinder single layer"), createDefaultSample());
}

Instrument *MainWindow::createDefaultInstrument()
{
    Instrument *p_result = new Instrument;
    p_result->setBeamParameters(0.1*Units::nanometer, 0.4*Units::degree, 0.0);
    p_result->setBeamIntensity(1e7);
    p_result->setDetectorParameters(100, 0.0, 3.0*Units::degree,
                                    100, 0.0, 3.0*Units::degree);
    return p_result;
}

ISample *MainWindow::createDefaultSample()
{
    MultiLayer *p_multi_layer = new MultiLayer();
    const IMaterial *mAir = MaterialManager::getHomogeneousMaterial("Air", 0., 0.);
    const IMaterial *mSubstrate = MaterialManager::getHomogeneousMaterial("Substrate", 6e-6, 2e-8);
    const IMaterial *mParticle = MaterialManager::getHomogeneousMaterial("Particle", 6e-4, 2e-8);
    Layer air_layer;
    air_layer.setMaterial(mAir);
    Layer substrate_layer;
    substrate_layer.setMaterial(mSubstrate);
    ParticleDecoration particle_decoration( new Particle(mParticle, new FormFactorCylinder(5*Units::nanometer, 5*Units::nanometer)));
    particle_decoration.addInterferenceFunction(new InterferenceFunctionNone());
    air_layer.setDecoration(particle_decoration);

    p_multi_layer->addLayer(air_layer);
    p_multi_layer->addLayer(substrate_layer);
    return p_multi_layer;
}
