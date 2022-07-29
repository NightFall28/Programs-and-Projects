#include "sequence1.h"
#include <cstdlib>

namespace main_savitch_3 {

	sequence::sequence() {
		used = 0;
		current_index = 0;
	}

	void sequence::start()
	{
		current_index = 0;
	}

	void sequence::advance()
	{
		if (is_item()) {
			current_index++;
		}
	}
	void sequence::insert(const value_type& entry)
	{
		// ensure that there is available space for new item
		if (size() < CAPACITY) {
			
			// If there is no current item,
			// then set current_index to the front so that
			// the new entry will be placed at the front of the array.
			if (!is_item())
				current_index = 0;

			// Starting at end of relevant items, shift items over to make room
			for (size_type i = used; i > current_index; i--)
				data[i] = data[i - 1];

			// insert new entry at current_index
			data[current_index] = entry;
			// increment number of items used
			used++;
		}
	}
	

	void sequence::attach(const value_type& entry)
	{
		// ensure that there is available space for new item
		if (size() < CAPACITY) {

			//If there is no current item, then the new entry has been attached to the end of the sequence
			if (!is_item())
			{
				current_index = used - 1;
			}

			for (int i = used; i > (current_index + 1); i--)
				data[i] = data[i - 1];

			data[current_index + 1] = entry;
			//increment the current index to make sure that the current item is the newly attached element
			current_index++;
			used++;
		}
	}
	

	void sequence::remove_current()
	{
		if (is_item()) {
			for (size_type i = current_index + 1; i < used; i++) {
				data[i - 1] = data[i];
			}
			used--;
		}
	}

	sequence::size_type sequence::size() const
	{
		return used;
	}

	bool sequence::is_item() const
	{
		return (current_index < used);
	}

	sequence::value_type sequence::current() const
	{
		if (is_item()) {
			return data[current_index];
		}
	}
}
