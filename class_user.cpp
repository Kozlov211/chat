#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;


class User {
public:
	User(const std::string& name,const std::string& password) {
		this->name = name;
		this->password = password;
		this->user_id = ++count;
		set_status(true);
		this->current_chat = "global";
		
	}
	uint32_t get_id() {
		return this->user_id;
	}
	std::string get_name() {
		return this->name;
	}
	std::string get_password() {
		return this->password;
	}
	bool get_status() {
		return this->status;
	}
	std::set<string>  get_friends() {
		return this->friends_list;   
	}
	std::set<string> get_chat_list() {
		return this->chat_list;
	}
	void set_status(const bool& status) {
		this->status = status;
	}
	void add_friend(const std::string& name) {
		this->friends_list.insert(name);
	}
	void remove_friend(const std::string& name) {
		this->friends_list.erase(name);
	}
	void print_friends() {
		for (const std::string& name : this->friends_list) {
			std::cout << name << std::endl;
		}
	}
	static uint32_t count;
private:
	uint32_t user_id; 
	std::string name; 
	std::string password;
	bool status; 
	std::set<string> friends_list;
	std::set<string> chat_list;
	std::vector<string> friend_request;
	std::string current_chat; 
};

uint32_t User::count = 0; // Объявление статической переменной класса User

int main() {
	User Name("Вася"s, "123ф"s);
	Name.print_friends();
	return 0;
}
