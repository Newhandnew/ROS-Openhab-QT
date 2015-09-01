/**
 * @file /include/openhab_home/main_window.hpp
 *
 * @brief Qt based gui for openhab_home.
 *
 * @date November 2010
 **/
#ifndef openhab_home_MAIN_WINDOW_H
#define openhab_home_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace openhab_home {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();

	void ReadSettings(); // Load up qt program settings at startup
	void WriteSettings(); // Save qt program settings when closing

	//test program


	void closeEvent(QCloseEvent *event); // Overloaded function
	void showNoMasterMessage();

	// void on_btn_Input_clicked();
Q_SIGNALS:
	void on_btn_Input_clicked();


public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/
	void on_actionAbout_triggered();
	void on_button_connect_clicked(bool check );

	//test program
	void WriteDisplay();
	void sendMessage();
	//void on_btn_Input_triggered();

	void on_checkbox_use_environment_stateChanged(int state);

    /******************************************
    ** Manual connections
    *******************************************/
    void updateLoggingView(); // no idea why this can't connect automatically

private:
	Ui::MainWindowDesign ui;
	QNode qnode;
};

}  // namespace openhab_home

#endif // openhab_home_MAIN_WINDOW_H
