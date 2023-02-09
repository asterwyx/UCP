#include "mainwindow.h"

#include <QColorDialog>
#include <QInputDialog>
#include <QFontDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    m_font("JetBrains Mono NL"),
    m_fontColor(Qt::white)
{
    setUI();
    updateEditorFont();
    connect(m_openAction, SIGNAL(triggered(bool)), this, SLOT(openFile()));
    connect(m_fontColorAction, SIGNAL(triggered(bool)), this, SLOT(selectFontColor()));
    connect(m_fontAction, SIGNAL(triggered(bool)), this, SLOT(selectFont()));
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
    m_editMenu = m_menuBar->addMenu(tr("Edit"));
    m_fontMenu = m_editMenu->addMenu(tr("Font"));
    m_fontColorAction = m_fontMenu->addAction(tr("Font color"));
    m_fontAction = m_fontMenu->addAction(tr("Font family"));
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

void MainWindow::selectFontColor()
{
    m_fontColor = QColorDialog::getColor();
    qDebug() << m_fontColor;
    updateEditorFont();
}

void MainWindow::selectFont()
{
    bool ok = false;
    m_font = QFontDialog::getFont(&ok);
    qDebug() << m_font;
    if (ok) {
        updateEditorFont();
    }
}

void MainWindow::updateEditorFont()
{
    m_editor->setFont(m_font);
    m_editor->setTextColor(m_fontColor);
    m_editor->update();
}

