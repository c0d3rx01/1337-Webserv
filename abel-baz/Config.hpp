#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>

// Represents one location block (inside a server block)
struct LocationConfig
{
    std::string path;                  // location /this_path
    std::string root;                  // root /some/dir
    std::string index;                 // index.html
    std::vector<std::string> methods; // GET, POST, DELETE
    bool autoindex;                   // on or off
    std::string upload_dir;           // where to store uploaded files
    std::string redirection;          // optional: redirect to another URL
    std::vector<std::string> cgi_extension;        // e.g. ".php", ".py" <-- khask trdo vector 7int i9dr idirhom bjooj (multiple cgi)
    bool empty;

    LocationConfig() : autoindex(false), empty(true) {}
};

// Represents one server block
struct HostPort
{
    std::string listen_host; // e.g. "0.0.0.0"
    int listen_port;          // e.g. 80
};

struct ServerConfig
{
    std::vector<HostPort> listens; // e.g. "
    std::vector<std::string> server_name;          // e.g. "localhost"
    std::map<int, std::string> error_pages; // 404 => "/404.html"
    std::vector<LocationConfig> locations;  // List of locations
    size_t max_body_size;
    int keep_alive_timeout; // in seconds, default 5 seconds

    ServerConfig() : max_body_size(1000000), keep_alive_timeout(10) {} // example default: 1 MB
};

// Holds the full parsed config file
struct Config
{
    std::vector<ServerConfig> servers;

    int getKeepAliveTimeout(std::string host, int port) const;
    size_t getMaxBodySize(std::string host, int port) const;
};

#endif // CONFIG_HPP

