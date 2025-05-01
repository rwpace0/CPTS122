/*
Name: Reid Pace
Class: 122
Assignment: PA6
Date: March 20th, 2025
Lab Section: 10
Description: BSTNode class definitions
*/

#include "BSTNode.hpp"


char BSTNode::getEnglish(void) {
    return english;
}


string BSTNode::getMorse(void) {
    return morse;
}


BSTNode* BSTNode::getLeft(void) {
    return left;
}


BSTNode* BSTNode::getRight(void) {
    return right;
}


void BSTNode::setEnglish(char newCharacter) {
    english = newCharacter;
}


void BSTNode::setMorse(string newMorse) {
    morse = newMorse;
}


void BSTNode::setLeft(BSTNode* newLeft) {
    left = newLeft;
}


void BSTNode::setRight(BSTNode* newRight) {
    right = newRight;
}