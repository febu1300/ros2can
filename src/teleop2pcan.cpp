#include "foxypcan.h"
using std::placeholders::_1;
using builtin_interfaces::msg::Time;

using namespace std::chrono_literals;

class TeleopPcanSubscriber : public rclcpp::Node
{
  public:
    TeleopPcanSubscriber()
    : Node("teleop_pcan_subscriber")
    {
      subscription_ = this->create_subscription<geometry_msgs::msg::Twist>(
      "cmd_vel", 1, std::bind(&TeleopPcanSubscriber::topic_callback, this, _1));
    }

  private:
 
  
    void topic_callback(const geometry_msgs::msg::Twist::SharedPtr msg) const
    {
	bool nFlagLenk=0;
	bool nFlagAntrieb=0;
    if (( float)msg->angular.z < 0.0){
   nFlagLenk=1;
  }
  
  if (( float)msg->linear.x < 0.0){
   nFlagAntrieb=1;
  }
  
    	Message.ID = 0x77;
	Message.LEN = 8;
	Message.MSGTYPE = PCAN_MESSAGE_EXTENDED;
	memset(Message.DATA, '\0', sizeof(Message.DATA));
      
    	Message.DATA[0]=std::abs(msg->angular.z);
	Message.DATA[1]=nFlagLenk;
	Message.DATA[2]=(int)std::round(std::abs(msg->linear.x));
	Message.DATA[3]=nFlagAntrieb;
	Message.DATA[4]=0;
	Message.DATA[5]=0;
	Message.DATA[6]=0;
	Message.DATA[7]=0;
      Status = CAN_Write(pcan_device, &Message);
            
      RCLCPP_INFO(this->get_logger(), "I heard: %f %f %f",msg->linear.x,msg->linear.y,msg->angular.z);
    }
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_;
   
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  Status =  CAN_Initialize(pcan_device, PCAN_BAUD_500K, 0, 0, 0);
  rclcpp::spin(std::make_shared<TeleopPcanSubscriber>());
  rclcpp::shutdown();
  return 0;
  
}
