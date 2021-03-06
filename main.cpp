#include <glog/logging.h>

#include "json11.hpp"

int main(int argc, char** argv)
{
    google::InitGoogleLogging("wnworker");
    gflags::SetVersionString("whynot");
    google::ParseCommandLineFlags(&argc, &argv, true);
    FLAGS_logtostderr = true;
    std::string err;

    LOG(INFO) << "hello";

    // create a json object:
    json11::Json o = json11::Json::object{
        {"1", std::string("one")},
        {"2", std::string("two")},
        {"3", 3},
    };

    // serialize to a string:
    LOG(INFO) << "o:" << o.dump();
    CHECK_EQ(o["1"].string_value(), "one");
    CHECK_EQ(o["1"].type(), json11::Json::STRING);
    CHECK_EQ(o["2"].string_value(), "two");
    CHECK_EQ(o["2"].type(), json11::Json::STRING);
    CHECK_EQ(o["3"].int_value(), 3);
    CHECK_EQ(o["3"].type(), json11::Json::NUMBER);

    // parse json string
    json11::Json oo = json11::Json::parse(o.dump(), err);
    CHECK_EQ(err, "");
    LOG(INFO) << "oo:" << oo.dump();

    // should be the same string:
    CHECK_EQ(oo.dump(), o.dump());

    return EXIT_SUCCESS;
}
