from django.urls import include, path
from second_app import views

urlpatterns = [
    path('help/', views.help, name='help'),
    path('', views.user, name='user'),
]
