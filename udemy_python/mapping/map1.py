import folium
import pandas

def get_color(elevation):
    if elevation <= 2000:
        return "green"
    elif elevation <= 3000:
        return "orange"
    else:
        return "red"

data = pandas.read_csv("Volcanoes.txt")
map = folium.Map(location=[40, -99], zoom_start=5, tiles="Stamen Terrain")
# map = folium.Map(location=[40, -99], zoom_start=5)
fg = folium.FeatureGroup(name="my map")

html = """<h4>Volcano information:</h4>
Height: %s m
"""

fgv = folium.FeatureGroup(name="Volcanoes")

for lat, lon, el in zip(list(data['LAT']), list(data['LON']), list(data['ELEV'])):
    iframe = folium.IFrame(html=html % str(el), width=200, height=100)
    c = get_color(el)
    # fg.add_child(folium.Marker(location=[lat,lon], popup=folium.Popup(iframe),
    #              icon=folium.Icon(icon='ok', icon_color='white', color=c)))
    
    fgv.add_child(folium.CircleMarker(location=[lat,lon], radius=5, color='black', fill_color=c,
                 popup=folium.Popup(iframe), fill_opacity=0.75))
          
fgp = folium.FeatureGroup(name="Population")       
fgp.add_child(folium.GeoJson(data=open('world.json', 'r', encoding='utf-8-sig').read(),
    style_function=lambda x:{'fillColor':'green' if x['properties']['POP2005'] < 10e6 
    else 'orange' if 10e6 <= x['properties']['POP2005'] < 50e6 else 'red'}))
      
map.add_child(fgv)
map.add_child(fgp)
map.add_child(folium.LayerControl())


# fg.add_child(folium.Marker(location=[35.9, -97.6], popup="Marker loc", icon=folium.Icon(color='green')))
# map.add_child(fg)
map.save("Map2.html")
