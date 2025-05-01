/*
Name: Reid Pace
Class: 122
Assignment: PA7
Date: March 29th, 2025
Lab Section: 10
Description: node template file
*/
#pragma once
#include "include.hpp"
#include "Data.hpp"

template <typename T>
class Node {
public:
	//constructor
	Node();
	//value init
	Node(const T& newData);
	//data getter
	T& getData();
	//constant data getter
	const T& getData() const;
	//next node getter
	Node<T>* getNext() const;
	//setter data
	void setData(const T& newData);
	//setter next
	void setNext(Node<T>* newNext);

private:
	T data;
	Node<T>* next;
};

template <typename T>
Node<T>::Node() : next(nullptr) {}

template <typename T>
Node<T>::Node(const T& newData) : data(newData), next(nullptr) {}

template <typename T>
 T& Node<T>::getData() {
	return data;
}

template <typename T>
const T& Node<T>::getData() const {
	return data;
}

template <typename T>
Node<T>* Node<T>::getNext() const{
	return next;
}

template <typename T>
void Node<T>::setData(const T& newData) {
	data = newData;
}

template <typename T>
void Node<T>::setNext(Node<T>* newNext) {
	next = newNext;
}