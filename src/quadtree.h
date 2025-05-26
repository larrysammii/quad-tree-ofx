#pragma once

#include "ofRectangle.h"
#include "ofVec2f.h"
#include <memory>
#include <ofMain.h>

class QuadTree {
private:
	std::vector<ofVec2f> points;
	std::unique_ptr<QuadTree> northWest;
	std::unique_ptr<QuadTree> northEast;
	std::unique_ptr<QuadTree> southWest;
	std::unique_ptr<QuadTree> southEast;

public:
	ofRectangle boundary {};

	int capacity {};
	QuadTree(const ofRectangle & boundary, int capacity);
	void insert(const ofVec2f & point);
	void subdivide();
	void draw();
};
