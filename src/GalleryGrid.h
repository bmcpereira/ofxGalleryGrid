#pragma once

#include "ofMain.h"
#include "GalleryElement.h"


class GalleryGrid {

public:

	void setup(vector<GalleryElement*> items);
	void update();
	void draw();
	void mousePressed(int x, int y, int button);
	void keyPressed(int key);
	void calculatePageLayout();
	void drawPagination();
	bool checkButtonHit(int hit_x, int hit_y, int x, int y, int w, int h);
	void checkPaginationHit(int hit_x, int hit_y);

	vector<GalleryElement*> items;	
	int elementsSize;

	// Grid Configuration
	int rowSize;
	int defaultColumnSize;
	int minRowSize;
	int maxRowSize;

	int hSpacing;
	int vSpacing;

	float pMarginLeft;
	float pMarginTop;

	int itemWidth;
	int itemHeight;

	int maxElementsPerPage;
	int nPages;
	int currentPage;
};

