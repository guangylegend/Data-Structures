#include "stdafx.h"
#include "CppUnitTest.h"
#include "../SplayTree/include/SplayTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTree {
	TEST_CLASS(UnitTestSplayTree) {
	public:

		TEST_METHOD(TestPlainInsert) {
			SplayTree* splayTree = new SplayTree();
			splayTree->insert(1);
			Assert::AreEqual(1, splayTree->size());
			splayTree->insert(3);
			Assert::AreEqual(2, splayTree->size());
			splayTree->insert(5);
			Assert::AreEqual(3, splayTree->size());
			splayTree->insert(-2);
			Assert::AreEqual(4, splayTree->size());
			std::vector<int> exp = std::vector<int>{ -2, 1, 3, 5 };
			std::vector<int> res = splayTree->inorderTraversal();
			Assert::AreEqual(exp.size(), res.size());
			for (int i = 0; i < (int)exp.size(); i++) {
				Assert::AreEqual(exp[i], res[i]);
			}
		}

		TEST_METHOD(TestPlainErase) {
			SplayTree* splayTree = new SplayTree();
			splayTree->insert(1);
			Assert::AreEqual(1, splayTree->size());
			splayTree->erase(1);
			Assert::AreEqual(0, splayTree->size());
			splayTree->insert(2);
			Assert::AreEqual(1, splayTree->size());
			splayTree->erase(2);
			Assert::AreEqual(0, splayTree->size());
			std::vector<int> res = splayTree->inorderTraversal();
			Assert::AreEqual(0, (int)res.size());
		}

		TEST_METHOD(TestPlainFind) {
			SplayTree* splayTree = new SplayTree();
			splayTree->insert(1);
			Assert::AreEqual(1, splayTree->size());
			splayTree->insert(2);
			Assert::AreEqual(2, splayTree->size());
			splayTree->insert(3);
			Assert::AreEqual(3, splayTree->size());
			Assert::IsNotNull(splayTree->find(1));
			Assert::IsNotNull(splayTree->find(2));
			Assert::IsNotNull(splayTree->find(3));
			Assert::IsNull(splayTree->find(4));
			Assert::IsNull(splayTree->find(-1));
		}

		TEST_METHOD(TestDuplicateErase) {
			SplayTree* splayTree = new SplayTree();
			splayTree->insert(1);
			Assert::AreEqual(1, splayTree->size());
			splayTree->insert(2);
			Assert::AreEqual(2, splayTree->size());
			splayTree->erase(2);
			Assert::AreEqual(1, splayTree->size());
			splayTree->erase(2);
			Assert::AreEqual(1, splayTree->size());
			std::vector<int> res = splayTree->inorderTraversal();
			Assert::AreEqual(1, (int)res.size());
		}

		TEST_METHOD(TestDuplicateFind) {
			SplayTree* splayTree = new SplayTree();
			splayTree->insert(1);
			Assert::AreEqual(1, splayTree->size());
			splayTree->insert(2);
			Assert::AreEqual(2, splayTree->size());
			splayTree->insert(3);
			Assert::AreEqual(3, splayTree->size());
			Assert::IsNotNull(splayTree->find(1));
			Assert::IsNotNull(splayTree->find(1));
			Assert::IsNotNull(splayTree->find(1));
		}

		TEST_METHOD(TestEraseNotExistingElement) {
			SplayTree* splayTree = new SplayTree();
			splayTree->insert(1);
			Assert::AreEqual(1, splayTree->size());
			splayTree->insert(2);
			Assert::AreEqual(2, splayTree->size());
			splayTree->erase(3);
			Assert::AreEqual(2, splayTree->size());
			std::vector<int> res = splayTree->inorderTraversal();
			Assert::AreEqual(2, (int)res.size());
		}

		TEST_METHOD(TestDuplicateInsert) {
			SplayTree* splayTree = new SplayTree();
			splayTree->insert(1);
			Assert::AreEqual(1, splayTree->size());
			splayTree->insert(2);
			Assert::AreEqual(2, splayTree->size());
			splayTree->insert(1);
			Assert::AreEqual(3, splayTree->size());
			std::vector<int> exp = std::vector<int>{ 1, 1, 2 };
			std::vector<int> res = splayTree->inorderTraversal();
			Assert::AreEqual(exp.size(), res.size());
			for (int i = 0; i < (int)exp.size(); i++) {
				Assert::AreEqual(exp[i], res[i]);
			}
		}

	};
}