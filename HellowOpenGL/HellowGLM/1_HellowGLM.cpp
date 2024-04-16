#ifndef __cplusplus
#error This file works only with C++
#endif

#pragma warning(disable:4711 4710 4100 4514 4626 4774 4365 4625 4464 4571 4201 5026 5027 5039)

#define GLM_FORCE_SWIZZLE//.xxyy와 같은 수의질 오퍼레이터가 glm에서도 사용가능하게
#include<glm/glm.hpp>
#include<glm/gtx/string_cast.hpp>//to_string()사용가능
#include<glm/gtc/type_ptr.hpp>//make_mat4() 어떤 포인터를 자료형으로 변환할수 있다.

#include<iostream>
using namespace std;


int main(void) {
	// glm test
	glm::vec4 a(1.0f, 2.0f, 3.0f, 1.0f);
	glm::vec4 b = glm::vec4(2.0f, 3.0f, 1.0f, 1.0f);
	glm::vec4 c = a + b;
	float d = glm::dot(a, b);
	std::cout << glm::to_string(a) << " + " << std::endl;
	std::cout << glm::to_string(b) << " --> " << std::endl;
	std::cout << glm::to_string(c) << std::endl;
	std::cout << "a . b = " << d << std::endl;
	// glm test
	glm::vec4 pos = glm::vec4(1.0f, 2.0f, 3.0f, 1.0f);
	std::cout << "pos = " << glm::to_string(pos) << std::endl;
	const float mat_val[] = { // CAUTION: column major
		2.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 3.0f, 0.0f, 2.0f,
		0.0f, 0.0f, 1.0f, 3.0f,
		0.0f, 0.0f, 0.0f, 1.0f,
	};
	glm::mat4 mat = glm::make_mat4(mat_val);
	std::cout << "mat = " << glm::to_string(mat) << std::endl;
	std::cout << "mat * pos = " << glm::to_string(mat * pos) << std::endl;
	std::cout << "pos * mat = " << glm::to_string(pos * mat) << std::endl;
	// done
	return 0;
}
