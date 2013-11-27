use cairo, gtk
import cairo/[Cairo, GdkCairo]
import gtk/[Gtk, Widget, Window]
import structs/ArrayList
import Grid

Paintable: class {
    f: Func (CairoContext)

    init: func (=f)

    call: func (cr: CairoContext) {
        f(cr)
    }
}

Canvas: class {

    cr: GdkContext
    win: Window
    grid: Grid
    paints := ArrayList<Paintable> new()
    
    repaintCount := 0
	
    init: func (width, height: Int) {
        win = Window new("Hai.")
        win setUSize(width, height) //.connect("delete_event", exit)
        win setAppPaintable(true)

        win connect("expose-event", ||
            onExpose()
        )
        win showAll()

        //Gtk main()
    }
    
    addPaint: func (f: Func (CairoContext)) {
        paints add(Paintable new(f))
    }
	
    update: func {
        if(repaintCount >= 0) {
            win forceRepaint(true)
            repaintCount = 8
        } else {
            repaintCount -= 1
        }
    }
	
    onExpose: func -> Bool {
        // expose event is sent when the widget (or parts of it) needs to be redrawn.
        // we repaint everything then.
        cr = GdkContext new(win getWindow())
        repaint(cr)
        cr destroy()
        return true
    }
	
    repaint: func (cr: CairoContext) {
        
        // code from test.ooc! 
        cr setSourceRGB(0, 0, 0)
        cr paint()

        for(paint in paints) {
            paint call(cr)
        }

        /*
		cr setLineWidth(15)
		cr setSourceRGB(255, 0, 0)
		cr moveTo(0, -100)
		cr lineTo(100, 100)
		cr relLineTo(-200, 0)
		cr closePath()
		cr stroke()
        */
    }


}
