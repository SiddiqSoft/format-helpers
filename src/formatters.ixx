/*
	Formatters for C++20
	Version 1.0.0

	https://github.com/SiddiqSoft/format-helpers

	BSD 3-Clause License

	Copyright (c) 2021, Siddiq Software LLC
	All rights reserved.

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:

	1. Redistributions of source code must retain the above copyright notice, this
	   list of conditions and the following disclaimer.

	2. Redistributions in binary form must reproduce the above copyright notice,
	   this list of conditions and the following disclaimer in the documentation
	   and/or other materials provided with the distribution.

	3. Neither the name of the copyright holder nor the names of its
	   contributors may be used to endorse or promote products derived from
	   this software without specific prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
	AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
	FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
	DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
	SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
	CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
	OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
	OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
module;


#include <format>
#include <atomic>

export module FormatterHelpers;

template <class T, class CharT> export struct std::formatter<std::atomic<T>, CharT> : std::formatter<T, CharT>
{
	auto format(const std::atomic<T>& sv, std::format_context& ctx) { return std::formatter<T, CharT>::format(sv.load(), ctx); }
};


template <> export struct std::formatter<std::atomic_int> : std::formatter<int>
{
	template <typename FormatContext> auto format(const std::atomic_int& sl, FormatContext& ctx)
	{
		return std::formatter<int>::format(sl.load(), ctx);
	}
};


template <> export struct std::formatter<std::atomic_uint> : std::formatter<unsigned int>
{
	template <typename FormatContext> auto format(const std::atomic_uint& sl, FormatContext& ctx)
	{
		return std::formatter<unsigned int>::format(sl.load(), ctx);
	}
};


template <> export struct std::formatter<std::atomic_uint64_t> : std::formatter<uint64_t>
{
	auto format(const std::atomic_uint64_t& sv, std::format_context& ctx)
	{
		return std::formatter<uint64_t>::format(sv.load(), ctx);
	}
};


template <> export export struct std::formatter<std::atomic_int64_t> : std::formatter<int64_t>
{
	auto format(const std::atomic_int64_t& sv, std::format_context& ctx) { return std::formatter<int64_t>::format(sv.load(), ctx); }
};


template <> export struct std::formatter<std::atomic_bool> : std::formatter<bool>
{
	template <typename FormatContext> auto format(const std::atomic_bool& sl, FormatContext& ctx)
	{
		return std::formatter<bool>::format(sl.load(), ctx);
	}
};


template <> export struct std::formatter<std::exception> : std::formatter<const char*>
{
	auto format(const std::exception& se, std::format_context& ctx) { return std::formatter<const char*>::format(se.what(), ctx); }
};


/*
 * The following will be enabled if the corresponding library is present
 */

#if defined(NLOHMANN_JSON_VERSION_MAJOR) && defined(NLOHMANN_JSON_VERSION_MINOR)
template <> export struct std::formatter<nlohmann::json> : std::formatter<std::string>
{
	auto format(const nlohmann::json& sv, std::format_context& ctx) { return std::formatter<std::string>::format(sv.dump(), ctx); }
};
#endif

#endif
