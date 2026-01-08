/**
* @file main.cpp
* @data 2026-01-09-1.04
* @auther jssun
* @note make a string class by myself
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cassert>	//< 提供断言功能 用于在程序运行时检查某些条件是否为真，假会终止并输出错误信息

namespace W
{
	class string
	{
	public:
		//< 默认构造函数
		string(const char* str = "")
		{
			//< 初始化
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			// 正确的 strcpy_s 用法：strcpy_s(目标, 目标缓冲区大小, 源)
			strcpy(_str, str);
		}
		//< 析构函数
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
		const char* c_str() const { return _str; }
	private:
		/**
		* @note 需要存储字符串的数组 字符指针
		* 分配的内存容量 8字节无符号整数
		* 当前字符串的有效长度 同上
		*/
		char* _str;
		size_t _capacity;
		size_t _size;

	};
}

int main() 
{
	W::string s("fuck you c++");
	std::cout << s.c_str() << std::endl;
	return 0;
}