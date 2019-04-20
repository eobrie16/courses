from django.shortcuts import render
from django.http import HttpResponse
from second_app.models import User
from . import forms

# Create your views here.
def index(request):
    return render(request, 'second_app/index.html')

def help(request):
    help_dict = {'help_me': "Help Page!!"}
    return render(request, 'second_app/help.html', context=help_dict)

def user_form(request):
    the_form = forms.UserForm()
    if request.method == 'POST':
        # do something with the form data
        f = forms.UserForm(request.POST)
        if f.is_valid():
            print("VALIDATION SUCCESS!")
            print("first ", f.cleaned_data['first_name'])
            print("email ", f.cleaned_data['email'])
            print("last ", f.cleaned_data['last_name'])
            f.save()
            return index(request)

    return render(request, 'second_app/user_form.html', {'form': the_form})

def user(request):
    user_list = User.objects.order_by('last_name')
    user_dict = {'users': user_list}

    return render(request, 'second_app/user.html', context=user_dict)
