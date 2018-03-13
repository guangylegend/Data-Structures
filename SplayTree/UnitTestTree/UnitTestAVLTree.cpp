#include "stdafx.h"
#include "CppUnitTest.h"
#include "../SplayTree/include/AVLTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTree {		
	TEST_CLASS(UnitTestAVLTree) {
	public:
		
		TEST_METHOD(TestPlainInsertion) {
			AVLTree* avlTree = new AVLTree();
			avlTree->insert(1);
			Assert::AreEqual(1, avlTree->size());
			avlTree->insert(3);
			Assert::AreEqual(2, avlTree->size());
			avlTree->insert(5);
			Assert::AreEqual(3, avlTree->size());
			avlTree->insert(-2);
			Assert::AreEqual(4, avlTree->size());
			std::vector<int> exp = std::vector<int>{ -2, 1, 3, 5 };
			std::vector<int> res = avlTree->inorderTraversal();
			Assert::AreEqual(exp.size(), res.size());
			for (int i = 0; i < (int)exp.size(); i++) {
				Assert::AreEqual(exp[i], res[i]);
			}
		}

	};
}