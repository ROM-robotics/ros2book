#include<chrono>
//#include<functional>
//#include<memory>
//#include<string>

#include "rclcpp/rclcpp.hpp"
#include "rom_msgs/msg/rpm.hpp"

class Publisher : public rclcpp::Node
{
	public:
		Publisher(): Node("my_publisher"),count_(0)
		{
			pub_ = this->create_publisher<rom_msgs::msg::Rpm>("desire_rpm",10);
			timer_ = this->create_wall_timer(std::chrono::milliseconds(500),std::bind(&Publisher::timer_callback,this));
		}
	private:
		void timer_callback()
		{
			auto message = rom_msgs::msg::Rpm();
			message.desire_rpm_right = 50;
			message.desire_rpm_left  = 50;
			RCLCPP_INFO(this->get_logger(),"Hi there");
			pub_->publish(message);
		}

		rclcpp::TimerBase::SharedPtr timer_;
		rclcpp::Publisher<rom_msgs::msg::Rpm>::SharedPtr pub_;
		size_t count_;
};
int main(int argc, char* argv[])
{
	rclcpp::init(argc,argv);
	rclcpp::spin( std::make_shared<Publisher>());
	rclcpp::shutdown();
	return 0;
}
