#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

// Simple SHA256 test without Qt
std::string simple_hash(const std::string& input) {
    // For testing, let's just create a deterministic but simple hash
    std::hash<std::string> hasher;
    size_t hash_value = hasher(input);
    
    std::stringstream ss;
    ss << std::hex << hash_value;
    return ss.str();
}

int main() {
    std::string passwords[] = {"admin123", "password", "123456", "test123"};
    
    std::cout << "Testing password hashing:\n";
    for (const auto& pwd : passwords) {
        std::cout << pwd << " -> " << simple_hash(pwd) << std::endl;
    }
    
    return 0;
}