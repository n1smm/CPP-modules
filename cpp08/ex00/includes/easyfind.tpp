template <typename T>
typename	T::iterator easyfind(T &container, int mark)
{
	typename	T::iterator it;
	it = std::find(container.begin(), container.end(), mark);
	if (it == container.end())
		throw std::runtime_error("No occurrence found");
	return (it);
}
