module;

#include <concepts>

export module Object:Concepts;

class NClass;
class NObject;

export
template <typename T>
concept BismuthClass = requires(T object)
{
	{object} -> std::convertible_to<NClass>;
};

export
template <typename T>
concept BismuthObject = requires(T object)
{
	{object} -> std::convertible_to<NObject>;
};

export
template <typename T, typename _Nt>
concept BismuthObjectDerived = requires(T object)
{
	{object} -> std::convertible_to<_Nt>;
};
