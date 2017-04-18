#pragma once

/*
	I still can't decide if I want to have the file loader be manually controlled and then its
	the users job to send it to the right file handler?
	That would be easiest for me of course but thats not really the problem here.

	For now I am going to build the bare minimum and see what is needed by the
	rest of the tool kit.
	If there is a major feature missing feel free to create a pull request or contact me
	directly.

	- Matt
*/

// The reason I am doing this all from "scratch" is for personal experience.
// The goal here is to create a system that provides the tools needed
// to create a "once only" file loader and a "behind the scenes" data transform system.
namespace Files
{
	enum class fileType
	{
		text, image, model, audio, // Generics. Possibly for errors if it can figure out the type but can't load it
		chai, png, txt, json, // Load in a special way?
		raw // Just load the file into memory and let the caller handle making sense of it.
	};

	class file
	{
	public:

		file(std::string);
		~file();

		// Make private?
		// Contains the file content
		std::vector<uint8_t> buffer;

		// The file location and unique name of
		// the object.
		std::string identity;

		// I honestly don't know if I should have more "logic" in here
		// Would a data "type" that is a glorified byte array need it?
		// I guess the need will show when I create the rest of the features
	};

	class FileTable
	{
	public:
		// Searches the loaded files and returns a <file> if found
		std::shared_ptr<file> findFile(std::string ident)
		{
			auto it = find_if(loaded.begin(), loaded.end(), [&ident](const std::shared_ptr<Files::file>& obj) {return; });
			if (it != loaded.end())
			{
				// found element. it is an iterator to the first matching element.
				// if you really need the index, you can also get it:
				auto index = std::distance(loaded.begin(), it);
				return loaded.at(index);
			}
			// This really needs to be fixed up.
			return nullptr;
		}

		// Searches the loaded files and returns, most likely, a ptrdif
		int findFileIndex(std::string ident)
		{
			auto it = find_if(loaded.begin(), loaded.end(), [&ident](const std::shared_ptr<Files::file>& obj) {return; });
			if (it != loaded.end())
			{
				return std::distance(loaded.begin(), it);
			}
			// This really needs to be fixed up, for a different reason.
			return 0;
		}

		// Creates a file and adds it to the loaded vector.
		std::shared_ptr<file>& createFile(const std::string& ident)
		{
			
			
			// loaded.emplace_back(std::shared_ptr<file>(new file(ident)));
		}

		// Create an empty file for containing data. Could be used for storage
		// or for exporting. Supports big files.
		std::shared_ptr<file>& createInternalFile(const std::string& ident, const unsigned long long int& fileSize)
		{
		}

		// Finds and deletes a file. I would not trust this over threads, will race.
		void deleteFile(std::string ident)
		{
			deleteFileByIndex(findFileIndex(ident));
		}

		// Deletes a file. I would not trust this over threads, will race.
		void deleteFileByIndex(int i)
		{
			std::vector<std::shared_ptr<file>>::iterator it = loaded.begin();
			std::advance(it, i);
			loaded.erase(it);
		}

	private:
		// Record of the locations of the files in memory.
		std::vector<std::shared_ptr<file>> loaded;
	}fTable;

	class FileLoader
	{
	public:
		FileLoader(std::string);
		~FileLoader();

	private:
		FileTable& g_fTable;
	};
}
