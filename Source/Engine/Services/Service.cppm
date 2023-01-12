module;

#include <concepts>

export module Services:Service;

export class SService {
public:
    
};

export
template <typename T>
concept BismuthService = requires(T object)
{
	{object} -> std::convertible_to<SService>;
};