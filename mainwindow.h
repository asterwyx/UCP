#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QTextCodec>
#include <QFileDialog>
#include <QTextStream>
#include <QMenuBar>
#include <QMessageBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setUI();

private:
    QTextCodec *m_codec;
    QString m_currentFile;
    QMenuBar *m_menuBar;
    QMenu *m_fileMenu;
    QAction *m_openAction;
    QAction *m_newAction;
    QAction *m_saveAction;
    QAction *m_saveAsAction;
    QAction *m_closeAction;
    QAction *m_quitAction;
    QMenu *m_editMenu;
    QMenu *m_fontMenu;
    QAction *m_fontColorAction;
    QAction *m_fontAction;
    QTextEdit *m_editor;
    QFont m_font;
    QColor m_fontColor;

private slots:
    void openFile();
    void newFile();
    void saveFile();
    void saveFileAs();
    void closeFile();
    void quitEditor();
    void selectFontColor();
    void selectFont();
    void updateEditorFont();
};
#endif // MAINWINDOW_H
