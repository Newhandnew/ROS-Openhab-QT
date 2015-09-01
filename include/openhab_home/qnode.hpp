/**
 * @file /include/openhab_home/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef openhab_home_QNODE_HPP_
#define openhab_home_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <string>
#include <QThread>
#include <QStringListModel>
#include <diagnostic_msgs/KeyValue.h>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace openhab_home {

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
    Q_OBJECT
public:
	QNode(int argc, char** argv );
	virtual ~QNode();
	bool init();
	bool init(const std::string &master_url, const std::string &host_url);
	void run();

	/*********************
	** Logging
	**********************/
	enum LogLevel {
	         Debug,
	         Info,
	         Warn,
	         Error,
	         Fatal
	 };
	 void sendMessage();


	QStringListModel* loggingModel() { return &logging_model; }
	void log( const LogLevel &level, const std::string &msg);

Q_SIGNALS:
	void loggingUpdated();
    void rosShutdown();
    void openhabUpdated();

private:
	int init_argc;
	char** init_argv;
	ros::Publisher chatter_publisher;
	ros::Publisher mqtt_publisher;
	ros::Subscriber mqtt_subscriber;
    QStringListModel logging_model;

    void openhabCallback(const diagnostic_msgs::KeyValue& msg);


};

}  // namespace openhab_home

#endif /* openhab_home_QNODE_HPP_ */
