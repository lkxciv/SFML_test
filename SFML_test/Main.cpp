//TODO: ?getroffene als gel�scht markieren und bei jedem Frame cleanup
//TODO: !listen statts vektoren
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
