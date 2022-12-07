#pragma once

import <concepts>;

class NClass;
class NObject;

template <typename T>
concept BismuthClass = requires(T a)
{
	{a} -> std::convertible_to<NClass>;
};

template <typename T>
concept BismuthObject = requires(T a)
{
	{a} -> std::convertible_to<NObject>;
};

template <typename T, typename _Nt>
concept BismuthObjectDerived = requires(T a)
{
	{a} -> std::convertible_to<_Nt>;
};
