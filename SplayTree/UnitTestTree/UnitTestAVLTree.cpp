#include "stdafx.h"
#include "CppUnitTest.h"
#include "../SplayTree/include/AVLTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTree {		
	TEST_CLASS(UnitTestAVLTree) {
	public:
		
		TEST_METHOD(TestPlainInsert) {
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

		TEST_METHOD(TestPlainErase) {
			AVLTree* avlTree = new AVLTree();
			avlTree->insert(1);
			Assert::AreEqual(1, avlTree->size());
			avlTree->erase(1);
			Assert::AreEqual(0, avlTree->size());
			avlTree->insert(2);
			Assert::AreEqual(1, avlTree->size());
			avlTree->erase(2);
			Assert::AreEqual(0, avlTree->size());
			std::vector<int> res = avlTree->inorderTraversal();
			Assert::AreEqual(0, (int)res.size());
		}

		TEST_METHOD(TestPlainFind) {
			AVLTree* avlTree = new AVLTree();
			avlTree->insert(1);
			Assert::AreEqual(1, avlTree->size());
			avlTree->insert(2);
			Assert::AreEqual(2, avlTree->size());
			avlTree->insert(3);
			Assert::AreEqual(3, avlTree->size());
			Assert::IsNotNull(avlTree->find(1));
			Assert::IsNotNull(avlTree->find(2));
			Assert::IsNotNull(avlTree->find(3));
			Assert::IsNull(avlTree->find(4));
			Assert::IsNull(avlTree->find(-1));
		}

		TEST_METHOD(TestDuplicateErase) {
			AVLTree* avlTree = new AVLTree();
			avlTree->insert(1);
			Assert::AreEqual(1, avlTree->size());
			avlTree->insert(2);
			Assert::AreEqual(2, avlTree->size());
			avlTree->erase(2);
			Assert::AreEqual(1, avlTree->size());
			avlTree->erase(2);
			Assert::AreEqual(1, avlTree->size());
			std::vector<int> res = avlTree->inorderTraversal();
			Assert::AreEqual(1, (int)res.size());
		}

		TEST_METHOD(TestDuplicateFind) {
			AVLTree* avlTree = new AVLTree();
			avlTree->insert(1);
			Assert::AreEqual(1, avlTree->size());
			avlTree->insert(2);
			Assert::AreEqual(2, avlTree->size());
			avlTree->insert(3);
			Assert::AreEqual(3, avlTree->size());
			Assert::IsNotNull(avlTree->find(1));
			Assert::IsNotNull(avlTree->find(1));
			Assert::IsNotNull(avlTree->find(1));
		}

		TEST_METHOD(TestEraseNotExistingElement) {
			AVLTree* avlTree = new AVLTree();
			avlTree->insert(1);
			Assert::AreEqual(1, avlTree->size());
			avlTree->insert(2);
			Assert::AreEqual(2, avlTree->size());
			avlTree->erase(3);
			Assert::AreEqual(2, avlTree->size());
			std::vector<int> res = avlTree->inorderTraversal();
			Assert::AreEqual(2, (int)res.size());
		}

		TEST_METHOD(TestDuplicateInsert) {
			AVLTree* avlTree = new AVLTree();
			avlTree->insert(1);
			Assert::AreEqual(1, avlTree->size());
			avlTree->insert(2);
			Assert::AreEqual(2, avlTree->size());
			avlTree->insert(1);
			Assert::AreEqual(3, avlTree->size());
			std::vector<int> exp = std::vector<int>{ 1, 1, 2 };
			std::vector<int> res = avlTree->inorderTraversal();
			Assert::AreEqual(exp.size(), res.size());
			for (int i = 0; i < (int)exp.size(); i++) {
				Assert::AreEqual(exp[i], res[i]);
			}
		}

	};
}