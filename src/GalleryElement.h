#pragma once

#include "ofMain.h"

class GalleryElement {
public:

	virtual void draw(int x, int y, int width, int height);
	virtual void update();
	virtual void onPressHandler();

	bool elementHit(int x, int y) {

		return (this->x <= x) && (x <= (this->x + this->itemWidth)) && (this->y <= y) && (y <= (this->y + this->itemHeight));
	}

	void setElementPage(int p) {
		elementPage = p;
	}
	int getElementPage() {
		return elementPage;
	}


	void setGridPosition(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void setItemSize(int w, int h) {
		this->itemWidth = w;
		this->itemHeight = h;
	}

	int getElementPage() {
		return elementPage;
	}

protected:
	int elementPage;
	int x;
	int y;
	int itemWidth;
	int itemHeight;
};