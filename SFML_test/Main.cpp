//TODO: entity.setOrigin(xoff, yoff), bei Player an Spitze
//TODO: Schüsse mit speed von char addiert
//TODO: treffer radius überarbeiten
//TODO: getroffene als gelöscht markieren und bei jedem Frame cleanup
//TODO: listen statts vektoren
//TODO: Enemy explodiert in Schüssen
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

