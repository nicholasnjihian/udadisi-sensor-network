## MQTT protocol

__MQTT__ is a machine-to-machine (M2M)/"Internet of Things" connectivity protocol. It was designed as an extremely lightweight publish/subscribe messaging transport. For more details see http://mqtt.org/.

By design MQTT operates over TCP protocol, so an __MQTTSN__ (For MQTT for Sensor Networks) was designed, which uses less resources and can operate over connectionless procols (such as UDP), but it requires a special gateway.

Mbed-os only allows you to create an MQTT client device, an external broker is needed for MQTT to operate. Clients can subscribe or publish to a topic, after connecting to a broker.

For normal, non-secure operation of the MQTT a TCPSocket has to be provided.

For secure communication over TCP a TLSSocket has to be provided.

For MQTT-SN communication a UDPSocket has to be provided.

For secure MQTT-SN communication, a DTLSSocket has to be provided.

After the socket is created, an instance of class MQTTClient can be created with the pointer to the socket as an argument. The class will distinguish between MQTT and MQTT-SN operation based on the socket's type.

[More Info](https://github.com/ARMmbed/mbed-mqtt)
