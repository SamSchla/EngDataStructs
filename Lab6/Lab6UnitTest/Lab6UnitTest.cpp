#include "CppUnitTest.h"
#include "../Lab6/StringBinaryTree.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab6UnitTest
{
	TEST_CLASS(Lab6UnitTest)
	{
	public:

		TEST_METHOD(TestInsert)
		{
			StringBinaryTree tree;
			
			tree.Insert("apple");
			tree.Insert("banana");
			tree.Insert("cherry");

			Assert::AreEqual(3, tree.Size(), L"Tree size should be 3 after three inserts.");

			Assert::AreEqual(std::string("apple"), tree.Find("apple"), L"Failed to find 'apple'");
			Assert::AreEqual(std::string("banana"), tree.Find("banana"), L"Failed to find 'banana'");
			Assert::AreEqual(std::string("cherry"), tree.Find("cherry"), L"Failed to find 'cherry'");
		}

		TEST_METHOD(TestFind)
		{
			StringBinaryTree tree;

			tree.Insert("dog");
			tree.Insert("cat");
			tree.Insert("bird");

			Assert::AreEqual(std::string("dog"), tree.Find("dog"), L"Failed to find 'dog'");
			Assert::AreEqual(std::string("cat"), tree.Find("cat"), L"Failed to find 'cat'");

			Assert::AreEqual(std::string(""), tree.Find("fish"), L"'fish' should not be found in the tree");
		}

		TEST_METHOD(TestRemove)
		{
			StringBinaryTree tree;

			tree.Insert("lion");
			tree.Insert("tiger");
			tree.Insert("bear");

			Assert::AreEqual(std::string("tiger"), tree.Remove("tiger"), L"Failed to remove 'tiger'");

			Assert::AreEqual(std::string(""), tree.Find("tiger"), L"'tiger' should not be found in the tree after removal");

			Assert::AreEqual(std::string("lion"), tree.Find("lion"), L"Failed to find 'lion'");
			Assert::AreEqual(std::string("bear"), tree.Find("bear"), L"Failed to find 'bear'");
			
			Assert::AreEqual(2, tree.Size(), L"Tree size should be 2 after one removal.");
		}
	};
}
