#include "ros/ros.h"
#include "lkh_ros/Solve.h"
using namespace std;
string lkh_path;

bool lkh_solve(lkh_ros::Solve::Request& req, lkh_ros::Solve::Response& res){
    std::string cmd = lkh_path + " " + req.problem_file;
    system(const_cast<char*>(cmd.c_str()));
    return true;
}

int main(int argc, char * argv[])
{
    // ros wrapper
    ros::init(argc, argv, "lkh_ros");
    ros::NodeHandle nh("");
    if(!nh.hasParam("Lkh_Path")){
        return 0;
    }
    nh.getParam("Lkh_Path", lkh_path);
    ros::ServiceServer lkh_server = nh.advertiseService("lkh_solve", lkh_solve);
    ros::spin();
    return 0;
}
