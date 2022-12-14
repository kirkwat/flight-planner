#include "catch.hpp"
#include "DSList.h"
#include "DSStack.h"
#include "DSAdjList.h"
#include "Destination.h"

TEST_CASE("Linked List class", "[linkedList]") {
    SECTION("Linked list creation and push back") {
        DSList<int> list1;
        REQUIRE(list1.getSize() == 0);
        list1.push_back(1);
        REQUIRE(list1.getSize() == 1);
        list1.push_back(1);
        REQUIRE(list1.getSize() == 2);
    }

    SECTION("Linked list with pointer data types") {
        DSList<int *> list2;
        list2.push_back(new int(10));
        REQUIRE(list2.getSize() == 1);
    }

    SECTION("Linked list accessor") {
        DSList<int> list3;
        list3.push_back(2);
        list3.push_back(4);
        list3.push_back(6);
        list3.push_back(8);
        REQUIRE(list3.at(0) == 2);
        REQUIRE(list3.at(1) == 4);
        REQUIRE(list3.at(2) == 6);
        REQUIRE(list3.at(3) == 8);
    }

    SECTION("Linked list nodes connection") {
        DSList<int> list4;
        list4.push_back(3);
        list4.push_back(6);
        list4.push_back(9);
        list4.push_back(12);
        REQUIRE(list4.getNext(2) == list4.nodeAt(3));
        REQUIRE(list4.getPrevious(3) == list4.nodeAt(2));
    }

    SECTION("Linked list insert after function") {
        DSList<int> list5;
        list5.push_back(1);
        list5.push_back(3);
        list5.push_back(5);
        list5.push_back(7);
        list5.InsertAfter(2, 4);
        REQUIRE(list5.getSize() == 5);
        REQUIRE(list5.at(0) == 1);
        REQUIRE(list5.at(1) == 3);
        REQUIRE(list5.at(2) == 5);
        REQUIRE(list5.at(3) == 4);
        REQUIRE(list5.at(4) == 7);
    }

    SECTION("Linked list insert in front function") {
        DSList<int> list6;
        list6.insert_front(1);
        list6.insert_front(3);
        list6.insert_front(5);
        list6.insert_front(7);
        REQUIRE(list6.getSize() == 4);
        REQUIRE(list6.at(0) == 7);
        REQUIRE(list6.at(1) == 5);
        REQUIRE(list6.at(2) == 3);
        REQUIRE(list6.at(3) == 1);
    }

    SECTION("Linked list remove function") {
        DSList<int> list7;
        list7.push_back(2);
        list7.push_back(4);
        list7.push_back(6);
        list7.push_back(8);
        list7.removeAt(2);
        REQUIRE(list7.getSize() == 3);
        REQUIRE(list7.at(0) == 2);
        REQUIRE(list7.at(1) == 4);
        REQUIRE(list7.at(2) == 8);
    }

    SECTION("Linked list iterating mechanism") {
        DSList<int> list8;
        REQUIRE(list8.ITRgetPointer()==nullptr);
        list8.push_back(2);
        list8.push_back(4);
        list8.push_back(6);
        list8.push_back(8);
        list8.push_back(10);
        REQUIRE(list8.ITRgetPayload()==2);
        list8.ITRnext();
        REQUIRE(list8.ITRgetPayload()==4);
        list8.ITRnext();
        REQUIRE(list8.ITRgetPayload()==6);
        list8.ITRnext();
        REQUIRE(list8.ITRgetPayload()==8);
        list8.ITRnext();
        REQUIRE(list8.ITRgetPayload()==10);
        list8.ITRnext();
        REQUIRE(list8.ITRgetPointer()==nullptr);
        list8.ITRreset();
        REQUIRE(list8.ITRgetPayload()==2);
    }

    SECTION("Linked list iterating mechanism with objects") {
        DSList<Destination> list9;
        REQUIRE(list9.ITRgetPointer()==nullptr);
        list9.push_back(Destination("Dallas"));
        list9.push_back(Destination("Austin"));
        list9.push_back(Destination("Houston"));
        list9.push_back(Destination("San Antonio"));
        list9.push_back(Destination("El Paso"));
        REQUIRE(list9.ITRgetPayload().getCityName()=="Dallas");
        list9.ITRnext();
        REQUIRE(list9.ITRgetPayload().getCityName()=="Austin");
        list9.ITRnext();
        REQUIRE(list9.ITRgetPayload().getCityName()=="Houston");
        list9.ITRnext();
        REQUIRE(list9.ITRgetPayload().getCityName()=="San Antonio");
        list9.ITRnext();
        REQUIRE(list9.ITRgetPayload().getCityName()=="El Paso");
        list9.ITRnext();
        REQUIRE(list9.ITRgetPointer()==nullptr);
        list9.ITRreset();
        REQUIRE(list9.ITRgetPayload().getCityName()=="Dallas");
    }
}

TEST_CASE("Stack class", "[stack]") {
    SECTION("Stack creation and push") {
        DSStack<int> stack1;
        REQUIRE(stack1.isEmpty());
        stack1.push(1);
        REQUIRE(!stack1.isEmpty());
    }

    SECTION("Stack pop function") {
        DSStack<int> stack2;
        REQUIRE(stack2.isEmpty());
        stack2.push(1);
        REQUIRE(!stack2.isEmpty());
        stack2.pop();
        REQUIRE(stack2.isEmpty());
    }

    SECTION("Stack peek function and more push/pop tests") {
        DSStack<int> stack3;
        REQUIRE(stack3.isEmpty());
        stack3.push(1);
        REQUIRE(!stack3.isEmpty());
        REQUIRE(stack3.peek()==1);
        stack3.push(2);
        REQUIRE(stack3.peek()==2);
        stack3.pop();
        REQUIRE(stack3.peek()==1);
        stack3.pop();
        REQUIRE(stack3.isEmpty());
    }
}

TEST_CASE("Adjacency list class", "[adjacencyList]") {
    SECTION("Adjacency list creation and push back") {
        DSAdjList list1;
        list1.addFlight("Dallas","Austin");
        list1.addFlight("Austin","Houston");
        list1.addFlight("Dallas","Houston");
        list1.addFlight("Austin","Chicago");
        //what list should look like:
        // D | A- > H
        // A | D -> H -> C
        // H | A -> D
        // C | A
        //check origin list
        REQUIRE(list1.getOriginAt(0).getCityName()=="Dallas");
        REQUIRE(list1.getOriginAt(1).getCityName()=="Austin");
        REQUIRE(list1.getOriginAt(2).getCityName()=="Houston");
        REQUIRE(list1.getOriginAt(3).getCityName()=="Chicago");
        //check destination lists
        //for dallas
        REQUIRE(list1.getDestinationAt(0,0).getCityName()=="Austin");
        REQUIRE(list1.getDestinationAt(0,1).getCityName()=="Houston");
        //for austin
        REQUIRE(list1.getDestinationAt(1,0).getCityName()=="Dallas");
        REQUIRE(list1.getDestinationAt(1,1).getCityName()=="Houston");
        REQUIRE(list1.getDestinationAt(1,2).getCityName()=="Chicago");
        //for houston
        REQUIRE(list1.getDestinationAt(2,0).getCityName()=="Austin");
        REQUIRE(list1.getDestinationAt(2,1).getCityName()=="Dallas");
        //for chicago
        REQUIRE(list1.getDestinationAt(3,0).getCityName()=="Austin");
    }
    SECTION("Adjacency list with linked list iterator") {
        DSAdjList list2;
        list2.addFlight("Dallas","Austin");
        list2.addFlight("Austin","Houston");
        list2.addFlight("Dallas","Houston");
        list2.addFlight("Austin","Chicago");
        //what list should look like:
        // D | A- > H
        // A | D -> H -> C
        // H | A -> D
        // C | A
        //dallas origin list
        REQUIRE(list2.originAt(0).getCityName()=="Dallas");
        REQUIRE(list2.originAt(0).getITR().getCityName()=="Austin");
        list2.originAt(0).nextITR();
        REQUIRE(list2.originAt(0).getITR().getCityName()=="Houston");
        list2.originAt(0).nextITR();
        REQUIRE(list2.originAt(0).getPointerITR()==nullptr);
        //austin origin list
        REQUIRE(list2.originAt(1).getCityName()=="Austin");
        REQUIRE(list2.originAt(1).getITR().getCityName()=="Dallas");
        list2.originAt(1).nextITR();
        REQUIRE(list2.originAt(1).getITR().getCityName()=="Houston");
        list2.originAt(1).nextITR();
        REQUIRE(list2.originAt(1).getITR().getCityName()=="Chicago");
        list2.originAt(1).nextITR();
        REQUIRE(list2.originAt(1).getPointerITR()==nullptr);
        //houston origin list
        REQUIRE(list2.originAt(2).getCityName()=="Houston");
        REQUIRE(list2.originAt(2).getITR().getCityName()=="Austin");
        list2.originAt(2).nextITR();
        REQUIRE(list2.originAt(2).getITR().getCityName()=="Dallas");
        list2.originAt(2).nextITR();
        REQUIRE(list2.originAt(2).getPointerITR()==nullptr);
        //chicago origin list
        REQUIRE(list2.originAt(3).getCityName()=="Chicago");
        REQUIRE(list2.originAt(3).getITR().getCityName()=="Austin");
        list2.originAt(3).nextITR();
        REQUIRE(list2.originAt(3).getPointerITR()==nullptr);
    }
}