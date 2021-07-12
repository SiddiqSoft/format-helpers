#include <format>
#include <atomic>
#include <exception>

#include "gtest/gtest.h"
#include "nlohmann/json.hpp"

#include "../src/formatters.hpp"


TEST(TestCaseName, Test_atomic_t_double)
{
	std::atomic<double> val {3.141};

	std::cerr << std::format("\t\t{} - Test. Compilation == success. val:{}\n", __func__, val);

	EXPECT_EQ(3.141, val.load()) << std::format("Expected value of val:{}", val);
	val = -3.141;
	EXPECT_EQ(-3.141, val.load()) << std::format("Expected value of val:{}", val);
}


TEST(TestCaseName, Test_atomic_t_wchar_t)
{
	std::atomic<wchar_t> val {L'E'};

	std::wcerr << std::format(L"\t\t{} - Test. Compilation == success. val:{}\n", __FUNCTIONW__, val);

	EXPECT_EQ(L'E', val.load()) << std::format(L"Expected value of val:{}", val);
}


TEST(TestCaseName, Test_atomic_t_char)
{
	std::atomic<char> val {'F'};

	std::cerr << std::format("\t\t{} - Test. Compilation == success. val:{}\n", __func__, val);

	EXPECT_EQ('F', val.load()) << std::format("Expected value of val:{}", val);
}


TEST(TestCaseName, Test_atomic_bool)
{
	std::atomic_bool val {false};

	std::cerr << std::format("\t\t{} - Test. Compilation == success. val:{}\n", __func__, val);

	EXPECT_FALSE(val.load()) << std::format("Expected value of val:{}", val);
	val = true;
	EXPECT_TRUE(val.load()) << std::format("Expected value of val:{}", val);
}


TEST(TestCaseName, Test_atomic_uint)
{
	std::atomic_uint val {0};

	std::cerr << std::format("\t\t{} - Test. Compilation == success. val:{}\n", __func__, val);

	EXPECT_EQ(0, val.load()) << std::format("Expected value of val:{}", val);
	val = -1;
	EXPECT_EQ(-1, val.load()) << std::format("Expected value of val:{}", val);
}


TEST(TestCaseName, Test_atomic_int)
{
	std::atomic_int val {0};

	std::cerr << std::format("\t\t{} - Test. Compilation == success. val:{}\n", __func__, val);

	EXPECT_EQ(0, val.load()) << std::format("Expected value of val:{}", val);
	val = 1;
	EXPECT_EQ(1, val.load()) << std::format("Expected value of val:{}", val);
}


TEST(TestCaseName, Test_atomic_uint64_t)
{
	std::atomic_uint64_t val {0};

	std::cerr << std::format("\t\t{} - Test. Compilation == success. val:{}\n", __func__, val);

	EXPECT_EQ(0, val.load()) << std::format("Expected value of val:{}", val);
	val = -1;
	EXPECT_EQ(-1, val.load()) << std::format("Expected value of val:{}", val);
}


TEST(TestCaseName, Test_atomic_int64_t)
{
	std::atomic_int64_t val {0};

	std::cerr << std::format("\t\t{} - Test. Compilation == success. val:{}\n", __func__, val);

	EXPECT_EQ(0, val.load()) << std::format("Expected value of val:{}", val);
	val = 1;
	EXPECT_EQ(1, val.load()) << std::format("Expected value of val:{}", val);
}


TEST(TestCaseName, Test_json)
{
	nlohmann::json val {{"foo", "bar"}, {"func", __func__}};

	std::cerr << std::format("\t\t{} - Test. Compilation == success. val:{}\n", __func__, val);

	EXPECT_EQ(2, val.size()) << std::format("Expected value of val:{}", val);
}
