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
map = folium.Map(location=[40, -90], zoom_start=5)
fgv = folium.FeatureGroup(name="Volcanoes")

for lat, lon, el in zip(list(data['LAT']), list(data['LON']), list(data['ELEV'])):
    #fg.add_child(folium.Marker(location=[lat,lon], popup=str(el), 
    #icon=folium.Icon(icon='ok', icon_color='white', color=get_color(el))))
    c = get_color(el)
    fgv.add_child(folium.CircleMarker(location=[lat,lon], radius=5, color=c, fill_color=c,
                 popup=str(el)+"m", fill_opacity=0.75))
          
fgp = folium.FeatureGroup(name="Population")       
fgp.add_child(folium.GeoJson(data=open('world.json', 'r', encoding='utf-8-sig'), 
    style_function=lambda x:{'fillColor':'green' if x['properties']['POP2005'] < 10e6 
    else 'orange' if 10e6 <= x['properties']['POP2005'] < 20e6 else 'red'}))
      
map.add_child(fgv)
map.add_child(fgp)
map.add_child(folium.LayerControl())
map.save("Map1.html")