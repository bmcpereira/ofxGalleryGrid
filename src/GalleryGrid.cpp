#include "GalleryGrid.h"

//--------------------------------------------------------------
void GalleryGrid::setup(vector<GalleryElement*> items) {
	rowSize = 3;
	defaultColumnSize = 4;
	minRowSize = 3;
	maxRowSize = 6;
	hSpacing = 40;
	vSpacing = 40;
	pMarginLeft = 0.35f;
	pMarginTop = 0.15f;
	itemWidth = 150;
	itemHeight = 150;

	currentPage = 1;
	
	this->items = items;
	
	calculatePageLayout();
}

//--------------------------------------------------------------
void GalleryGrid::update() {
	int pageStart = (maxElementsPerPage*(currentPage - 1));
	int pageEnd = min(this->elementsSize, (maxElementsPerPage*currentPage));

	for (int i = pageStart; i < pageEnd; i++) {
		items[i]->setItemSize(itemWidth, itemHeight);
		items[i]->update();
	}
}



//--------------------------------------------------------------
void GalleryGrid::draw() {
	int row = 0, col = 0;
	if (items.size() > 0) {
		ofSetColor(ofColor::white);

		int pageStart = (maxElementsPerPage*(currentPage - 1));
		int pageEnd = min(this->elementsSize, (maxElementsPerPage*currentPage));

		for (int i = pageStart ; i < pageEnd; i++) {
			int x = ((hSpacing + itemWidth)  * col) + ((ofGetWindowWidth() - ((rowSize * itemWidth) + ((rowSize-1) * hSpacing)))/2);
			int y = ((vSpacing + itemHeight) * row)  + (pMarginTop * ofGetWindowHeight());
			
			items[i]->setElementPage(currentPage);
			items[i]->draw(x, y, itemWidth, itemHeight);
			items[i]->setGridPosition(x, y);

			col++;
			if (col % rowSize == 0) {
				row++;
				col = 0;
			}
		}

		//DRAW THE PAGINATION CIRCLES
		drawPagination();
	}
}

//--------------------------------------------------------------
void GalleryGrid::keyPressed(int key) {
	switch (key) {
	case 'a':
		if (rowSize > minRowSize) { 
			rowSize--;
			calculatePageLayout();
		}
		break;
	case 'd':
		if (rowSize < maxRowSize) { 
			rowSize++;
			calculatePageLayout();
		};
		break;

	case OF_KEY_RIGHT:
		if(currentPage < nPages)
			currentPage++;
		break;

	case OF_KEY_LEFT:
		if (currentPage > 1)
			currentPage--;
		break;
	}
}


//--------------------------------------------------------------
void GalleryGrid::mousePressed(int x, int y, int button) {
	for (int i = 0; i < this->elementsSize; i++) {
		GalleryElement* elem = items[i];
		if (elem->elementHit(x, y) && button == 0 && elem->getElementPage() == currentPage) {
			elem->onPressHandler();
		}
	}
	//check pagination buttons hit
	checkPaginationHit(x, y);
}






void GalleryGrid::calculatePageLayout() {
	maxElementsPerPage = min((4 * rowSize), elementsSize);
	nPages = ceil((double)elementsSize / (double)maxElementsPerPage);

	if (currentPage > nPages)//back to previous page if the number of pages was reduced;
		currentPage--;
}

void GalleryGrid::drawPagination() {
	int circleRadius = 10;
	for (int i = 0; i < nPages; i++) {
		int x = (((circleRadius * 2 + 5)  * i) + ((ofGetWindowWidth() - ((circleRadius*nPages) + (5 * (nPages-1)))) / 2));
		int y = (0.88 * ofGetWindowHeight());
		if ((i + 1) == currentPage) {
			ofFill();
			ofSetColor(ofColor::black);
			ofCircle(x, y, circleRadius);
		}
		else {
			ofNoFill();
			ofSetColor(ofColor::black);
			ofCircle(x, y, circleRadius);
		}
	}
}

void GalleryGrid::checkPaginationHit(int hit_x, int hit_y) {
	int circleRadius = 10;
	for (int i = 0; i < nPages; i++) {
		int x = (((circleRadius * 2 + 5)  * i) + ((ofGetWindowWidth() - ((circleRadius*nPages) + (5 * (nPages - 1)))) / 2));
		int y = (0.88 * ofGetWindowHeight());
		
		if (checkButtonHit(hit_x, hit_y, x-10, y-10, 20, 20))
			currentPage = i+1;
	}
}


bool GalleryGrid::checkButtonHit(int hit_x, int hit_y,int x, int y, int w, int h) {
	return (x <= hit_x) && (hit_x <= (x + w)) && (y <= hit_y) && (hit_y <= (y + h));
}
