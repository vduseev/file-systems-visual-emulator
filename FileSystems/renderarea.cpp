#include "renderarea.h"

#include <QPainter>
#include <QMouseEvent>
#include <qdebug.h>

const int IdRole = Qt::UserRole;
const int xCount = 64;
const int yCount = 32;
const int cellWidth = 12;
const int cellHeight = 12;

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
    , m_allowDrawing( false )
    , m_page(0)
{
    shape = Rect;
    pixmap.load(":/images/qt-logo.png");

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    QLinearGradient linearGradient(0, 0, 40, 40);
    linearGradient.setColorAt(0.0, Qt::white);
    linearGradient.setColorAt(0.2, Qt::green);
    linearGradient.setColorAt(1.0, Qt::black);

	m_brushes.insert(FileSystem::Empty, QBrush(Qt::black, Qt::SolidPattern));
    m_brushes.insert(FileSystem::Red, QBrush(Qt::red, Qt::SolidPattern));
    m_brushes.insert(FileSystem::Green, linearGradient);
    m_brushes.insert(FileSystem::Blue, QBrush(Qt::blue, Qt::SolidPattern));
    m_brushes.insert(FileSystem::Cyan, QBrush(Qt::cyan, Qt::SolidPattern));
    m_brushes.insert(FileSystem::Magenta, QBrush(Qt::magenta, Qt::SolidPattern));
    m_brushes.insert(FileSystem::Yellow, QBrush(Qt::yellow, Qt::SolidPattern));
    m_brushes.insert(FileSystem::Black, QBrush(Qt::black, Qt::SolidPattern));
    m_brushes.insert(FileSystem::White, QBrush(Qt::white, Qt::SolidPattern));
    m_brushes.insert(FileSystem::DenseGreen, QBrush(Qt::green, Qt::Dense4Pattern));
    m_brushes.insert(FileSystem::DenseWhite, QBrush(Qt::white, Qt::Dense4Pattern));
    m_brushes.insert(FileSystem::DenseRed, QBrush(Qt::red, Qt::Dense4Pattern));
    m_brushes.insert(FileSystem::DenseBlue, QBrush(Qt::blue, Qt::Dense4Pattern));

    this->brush = m_brushes.value(FileSystem::Empty);
    this->pen = QPen(Qt::white, 0, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);
}

void RenderArea::setPen(const QPen &pen)
{
    this->pen = pen;
    update();
}

void RenderArea::setBrush( const QBrush &brush )
{
    this->brush = brush;
    update();
}

void RenderArea::setFileSystem( FileSystem *fileSystem )
{
    m_fileSystem = fileSystem;
    m_page = 0;
}

void RenderArea::setPage( int page )
{
    m_page = page;
	this->update();
}

void RenderArea::paintEvent( QPaintEvent * /* event */ )
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(palette().dark().color());
    QBrush br = QBrush(QColor(70, 70, 70));
    painter.setBrush(br);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));

    QRect rect(2, 2, 9, 9);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.setRenderHint(QPainter::Antialiasing, true);

    if ( m_allowDrawing )
    {
        int blocksCount = m_fileSystem->blockCount();
        int offset = 0;
        if (m_page * xCount * yCount < blocksCount)
        {
            offset = m_page * xCount * yCount;
            int blocksCountOnPage = blocksCount - offset;
            const unsigned char* blocks = m_fileSystem->blocks();
			FileSystem::Block type = FileSystem::DenseWhite;

            for (int x = 2, y = 2, i = 0; i < yCount; i++, x = 2)
            {
                for (int j = 0; j < xCount; j++)
                {
                    if (i * xCount + j < blocksCountOnPage)
                    {
						SIZE currentIndex = offset + i * xCount + j;
						if ( m_selectedBlocks.contains( currentIndex ) )
						{
							painter.setBrush(m_brushes.value(FileSystem::White));
						}
						else
						{
							type = ( FileSystem::Block )blocks[ currentIndex ];
							painter.setBrush(m_brushes.value(type));
						}
						painter.setPen(Qt::NoPen);
                    }
                    else
                    {
						painter.setBrush(Qt::NoBrush);
						painter.setPen(Qt::NoPen);
                    }

                    painter.save();
                    painter.translate(x, y);
                    painter.drawRect(rect);
                    painter.restore();

                    x += cellWidth;
                }
                y += cellHeight;
            }
        }
    }

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
}

void RenderArea::mousePressEvent( QMouseEvent* e )
{
	if ( m_allowDrawing )
	{
		if ( e->button() == Qt::LeftButton )
		{
			int x = e->x() - 2,
				y = e->y() - 2;
			int onPageIndex = ( y / cellHeight ) * xCount + ( x / cellWidth );
			SIZE blockCount = m_fileSystem->blockCount();
			SIZE offset = m_page * xCount * yCount;
			SIZE index = offset + onPageIndex;
			if ( index < 0 || index >= blockCount || onPageIndex >= 2048 )
			{
				// wrong selection
				emit blockSelected( -1 );
			}
			else
			{
				// norm selection
				m_selectedBlocks.clear();
				m_selectedBlocks.append( index );
				// emit notification
				emit blockSelected( index );
				// update
				this->update();
			}
		}
	}

	QWidget::mousePressEvent( e );
}

void RenderArea::allowDrawing()
{
    m_allowDrawing = true;
    this->update();
}

void RenderArea::forbidDrawing()
{
    m_allowDrawing = false;
    this->update();
}
