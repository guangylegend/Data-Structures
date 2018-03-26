#include "stdafx.h"
#include "CppUnitTest.h"
#include "../SegmentTree/include/SegmentTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestSegmentTree{		
	TEST_CLASS(UnitTest){
	public:
		static SegmentTree* tree;

		TEST_CLASS_INITIALIZE(setUp) {
			vector<int> arr = { 1,0,2,3,-1,-5,3,8,-4 };
			tree = new SegmentTree(arr);
		}

		TEST_CLASS_CLEANUP(tearDown) {
			tree = NULL;
		}

		TEST_METHOD(plainTest1){
			Assert::AreEqual(tree->sum(0, 8), 7);
			Assert::AreEqual(tree->sum(0, 5), 0);
			Assert::AreEqual(tree->sum(1, 1), 0);
		}

		TEST_METHOD(plainTest2) {
			tree->update(0, 0);
			Assert::AreEqual(tree->sum(0, 0), 0);
			Assert::AreEqual(tree->sum(0, 8), 6);
			tree->update(0, -1);
			Assert::AreEqual(tree->sum(0, 0), -1);
			Assert::AreEqual(tree->sum(0, 8), 5);
			tree->update(7, 0);
			Assert::AreEqual(tree->sum(7, 7), 0);
			Assert::AreEqual(tree->sum(0, 8), -3);
		}
	};
	SegmentTree* UnitTest::tree = NULL;
}