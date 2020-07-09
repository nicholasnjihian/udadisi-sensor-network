#include <MQTTClientMbedOs.h>

void setup_mqtt(std::string,int);

using std::string;

void setup_mqtt(const string& hostname, int port) {
	std<<cout<<" The hostname is "<<hostname<<" and the posrt num is "<<port<<std::endl;
	NetworkInterface *net = NetworkInterface::get_default_instance();
	TCPSocket socket;
	MQTTClient client(&socket);
	socket.open(net);
	socket.connect(hostname, port);
}
