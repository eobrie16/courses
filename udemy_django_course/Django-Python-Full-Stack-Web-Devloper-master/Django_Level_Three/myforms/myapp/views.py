from django.shortcuts import render
from . import forms

def index(request):
    return render(request, 'myapp/index.html')

def form_name_view(request):
    the_form = forms.FormName()
    if request.method == 'POST':
        # do something with the form data
        the_form = forms.FormName(request.POST)
        if the_form.is_valid():
            print("VALIDATION SUCCESS!")
            print("name ", the_form.cleaned_data['name'])
            print("email ", the_form.cleaned_data['email'])
            print("Text ", the_form.cleaned_data['text'])

    return render(request, 'myapp/forms.html', {'form': the_form})
