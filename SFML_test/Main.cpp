//TODO: entity.setOrigin(xoff, yoff), bei Player an Spitze
//TODO: Sch�sse mit speed von char addiert
//TODO: treffer radius �berarbeiten
//TODO: getroffene als gel�scht markieren und bei jedem Frame cleanup
//TODO: listen statts vektoren
//TODO: Enemy explodiert in Sch�ssen
#include "Outerdef.h"
#include "GameContext.h"
#include "GameWindow.h"

int main()
{
	GameContext context(1200, 900);
	GameWindow window(context);
	while (window.isOpen())
	{
		window.refreshEvents();
		context.refresh();
		window.drawDisp(context);
	}
}

