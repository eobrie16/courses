from django.shortcuts import render

def index(request):
    context_dict = {'text': "hello world", 'number': 100}
    return render(request, 'myapp/index.html', context=context_dict)

def other(request):
    return render(request, 'myapp/other.html')

def relurls(request):
    return render(request, 'myapp/relurls.html')
