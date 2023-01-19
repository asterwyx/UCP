#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setUI();
    connect(m_openAction, SIGNAL(triggered(bool)), this, SLOT(openFile()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::setUI()
{
    setWindowTitle(tr("UOS Editor"));
    setWindowIcon(QIcon::fromTheme("deepin-editor"));
    resize(800, 600);
    m_menuBar = new QMenuBar(this);
    this->setMenuBar(m_menuBar);
    m_fileMenu = m_menuBar->addMenu(tr("File"));
    m_openAction = m_fileMenu->addAction(tr("Open"));
    m_openAction->setShortcut(QKeySequence("Ctrl+O"));
    m_newAction = m_fileMenu->addAction(tr("New"));
    m_newAction->setShortcut(QKeySequence("Ctrl+N"));
    m_saveAction = m_fileMenu->addAction(tr("Save"));
    m_saveAction->setShortcut(QKeySequence("Ctrl+S"));
    m_saveAsAction = m_fileMenu->addAction(tr("Save as ..."));
    m_saveAsAction->setShortcut(QKeySequence("Ctrl+Shift+S"));
    m_closeAction = m_fileMenu->addAction(tr("Close"));
    m_closeAction->setShortcut(QKeySequence("Ctrl+W"));
    m_quitAction = m_fileMenu->addAction(tr("Quit"));
    m_quitAction->setShortcut(QKeySequence("Ctrl+Q"));
    m_editor = new QTextEdit(this);
    setCentralWidget(m_editor);

}

void MainWindow::openFile()
{
    m_currentFile = QFileDialog::getOpenFileName(this, tr("Open file"), "~", "Text File(*.txt *.h *.cpp)");
    QFile file(m_currentFile);
    if (file.exists()) {
        file.open(QFile::ReadOnly);
        m_editor->setText(file.readAll());
        file.close();
    }
}

void MainWindow::newFile()
{

}

void MainWindow::saveFile()
{

}

void MainWindow::saveFileAs()
{

}

void MainWindow::closeFile()
{

}

void MainWindow::quitEditor()
{

}

