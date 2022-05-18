#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "rom_msgs/msg/rpm.hpp"
using std::placeholders::_1;
class Subscriber : public rclcpp::Node
{
    public:
        Subscriber() : Node("rpm_subscriber")
        {
            sub_ = this->create_subscription<rom_msgs::msg::Rpm>(
                "desire_rpm",
                10,
                std::bind(&Subscriber::topic_callback, this, _1)
            );
        }
        
    private:
        
        void topic_callback(const rom_msgs::msg::Rpm::SharedPtr msg) const
        {
            int right = msg->desire_rpm_right; int left = msg->desire_rpm_left;
            RCLCPP_INFO(this->get_logger(), "i get %d and %d",right,left);
        }
        rclcpp::Subscription<rom_msgs::msg::Rpm>::SharedPtr sub_;
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin( std::make_shared<Subscriber>() );
    rclcpp::shutdown();
    return 0;
}