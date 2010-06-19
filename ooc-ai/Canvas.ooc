/*
use cairo, gtk
import cairo/[Cairo, GdkCairo]
import gtk/[Gtk, Widget, Window]

Canvas: class {

	cr: GdkContext
	win: Window
	
	init: func (width, height: Int) {
		win = Window new("Hai.")
		win setUSize(width, height) //.connect("delete_event", exit)
		win setAppPaintable(true)
		win connect("expose-event", onExpose as Func)
		win showAll()

		//Gtk main()
	}
	
	update: func {
		while(Gtk eventsPending()) {
			Gtk mainIteration()
		}
	}
	
	onExpose: func (widget: Widget, event, userData: Pointer) -> Bool {
		// expose event is sent when the widget (or parts of it) needs to be redrawn.
        // we repaint everything then.
		cr = GdkContext new(widget getWindow())
		repaint(cr)
		cr destroy()
		return true
	}
	
	repaint: func (cr: Context) {
		// code from test.ooc! 
		cr setSourceRGB(0, 0, 0)
		cr paint()

		cr setLineWidth(15)
		cr setSourceRGB(255, 0, 0)
		cr moveTo(0, -100)
		cr lineTo(100, 100)
		cr relLineTo(-200, 0)
		cr closePath()
		cr stroke()
	}


}
*/