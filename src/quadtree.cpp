#include "quadtree.h"
#include "ofGraphics.h"
#include "ofRectangle.h"
#include "ofVec2f.h"
#include <memory>

QuadTree::QuadTree(const ofRectangle & boundary, int capacity)
	: boundary { boundary }
	, capacity { capacity } {

	};

void QuadTree::subdivide() {
	float x = boundary.getX();
	float y = boundary.getY();
	float w = boundary.getWidth();
	float h = boundary.getHeight();

	// Northwest quadrant: Starts at (x, y) with half width and height
	ofRectangle nwRect(x, y, w / 2, h / 2);
	northWest = std::make_unique<QuadTree>(nwRect, capacity);

	// Northeast quadrant: Shifted right by half the width
	ofRectangle neRect(x + w / 2, y, w / 2, h / 2);
	northEast = std::make_unique<QuadTree>(neRect, capacity);

	// Southwest quadrant: Shifted down by half the height
	ofRectangle swRect(x, y + h / 2, w / 2, h / 2);
	southWest = std::make_unique<QuadTree>(swRect, capacity);

	// Southeast quadrant: Shifted right and down by half the width and height
	ofRectangle seRect(x + w / 2, y + h / 2, w / 2, h / 2);
	southEast = std::make_unique<QuadTree>(seRect, capacity);
}

void QuadTree::insert(const ofVec2f & point) {
	if (!boundary.inside(point)) {

		return;
	}

	if (northWest == nullptr) {
		if (points.size() < capacity) {
			points.push_back(point);
		} else {
			subdivide();
			for (const ofVec2f & p : points) {
				insert(p);
			}
			points.clear();
			insert(point);
		}
	} else {
		if (northWest->boundary.inside(point)) {
			northWest->insert(point);
		} else if (northEast->boundary.inside(point)) {
			northEast->insert(point);
		} else if (southWest->boundary.inside(point)) {
			southWest->insert(point);
		} else if (southEast->boundary.inside(point)) {
			southEast->insert(point);
		}
	}
}

void QuadTree::draw() {
	ofNoFill();
	ofSetColor(255);
	ofDrawRectangle(boundary);

	if (northWest == nullptr) {
		ofSetColor(255, 0, 0);
		// for (const ofVec2f & p : points) {
		// 	ofDrawCircle(p, 2);
		// }
	} else {
		northWest->draw();
		northEast->draw();
		southWest->draw();
		southEast->draw();
	}
}
