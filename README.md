# hkur_data_logger
Cascadia Motion Motor Controller CAN Protocol Documentation: https://app.box.com/s/vf9259qlaadhzxqiqrt5cco8xpsn84hk/file/27334613044 <BR>
Motor Controller Manual: https://wiki.neweagle.net/docs/Rinehart/PM100_User_Manual_3_2011.pdf <BR>
CAN Shield Arduino Library: https://github.com/DFRobot/DFRobot_MCP2515 <BR>
Arduino docs: https://www.arduino.cc/reference/en/ <BR>

# Functional requirements
1. Read data packets from the motor controller via CAN Bus (Perhaps try to capture the packets and print it to the screen first?)
2. Store the data packets to memory (Note: Arduino built-in memory is NOT enough. We may need an SD card for this)
3. Refer to the Motor Controller's CAN Protocol docs, translate the data to readable information (This is done in a PC connected to the arduino, or after fetching the data from the Arduino)

# Non-functional requirements
1. The data logger shares the same communication channel with the VCU. VCU "ideally" shall have the priority on the channel. If this cannot be done, at least do not hinder the VCU too often. (CAN uses message id to set priority for packets. According to the motor controller's VCU manual, the message from the motor controller has a smaller id than the command messages from the VCU. Therefore, we probably cannot give higher priority to VCU. Perhaps we set the data logger's frequency low to avoid it from fucking up the VCU)
