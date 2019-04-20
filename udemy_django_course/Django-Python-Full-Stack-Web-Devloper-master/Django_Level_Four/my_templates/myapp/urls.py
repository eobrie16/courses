from django.urls import path, include
from myapp import views

# template tagging
app_name = 'myapp'

urlpatterns = [
    path('relative/', views.relurls, name='relative'),
    path('other/', views.other, name='other')
]
