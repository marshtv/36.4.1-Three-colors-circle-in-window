#include <QApplication>
#include <QObject>
#include <QVBoxLayout>
#include <QSlider>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>

class Circle : public QWidget {
	//Q_OBJECT
public:
	Circle() = default;

	Circle(QWidget* parent);

	void paintEvent(QPaintEvent* e) override;

	QSize sizeHint() const override;

	QSize minimumSizeHint() const override;

public slots:
	void setRedColor();
	void setGreenColor();
	void setYellowColor();
private:
	QPixmap mRedCircle;
	QPixmap mGreenCircle;
	QPixmap mYellowCircle;
	QPixmap mCurrentCircle;
};

Circle::Circle(QWidget *parent) {
	setParent(parent);
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	mGreenCircle = QPixmap(R"(F:\__C++\Skillbox\36 Qt Widgets\36.4.1 Three colors Circle in window\Pixmaps\Green_circle.png)");
	mYellowCircle = QPixmap(R"(F:\__C++\Skillbox\36 Qt Widgets\36.4.1 Three colors Circle in window\Pixmaps\Yellow_circle.png)");
	mRedCircle = QPixmap(R"(F:\__C++\Skillbox\36 Qt Widgets\36.4.1 Three colors Circle in window\Pixmaps\Red_circle.png)");
	mCurrentCircle = mGreenCircle;
	setGeometry(mCurrentCircle.rect());
}

void Circle::paintEvent(QPaintEvent *e) {
	QPainter p(this);
	p.drawPixmap(e->rect(), mCurrentCircle);
}

QSize Circle::sizeHint() const {
	return {100, 100};
}

QSize Circle::minimumSizeHint() const {
	return sizeHint();
}

void Circle::setGreenColor() {
	mCurrentCircle = mGreenCircle;
	update();
}

void Circle::setYellowColor() {
	mCurrentCircle = mYellowCircle;
	update();
}

void Circle::setRedColor() {
	mCurrentCircle = mRedCircle;
	update();
}

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	auto* window = new QWidget;
	auto* circle = new Circle(window);
	circle->setFixedSize(200, 200);
	auto* slider = new QSlider(Qt::Horizontal, window);
	slider->setMinimum(0);
	slider->setMaximum(100);

	auto* layout = new QVBoxLayout(window);
	layout->addWidget(circle);
	layout->addWidget(slider);

	window->setFixedSize(220, 250);
	window->move(1000, 500);

	QObject::connect(slider, &QSlider::valueChanged,
					 [&](int newValue) {
						 if (newValue >= 0 && newValue <= 33) {
							 circle->setGreenColor();
						 } else if (newValue > 33 && newValue <= 66) {
							 circle->setYellowColor();
						 } else {
							 circle->setRedColor();
						 }
						});

	window->show();
	return QApplication::exec();
}
