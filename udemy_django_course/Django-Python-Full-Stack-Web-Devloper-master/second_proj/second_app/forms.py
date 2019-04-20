from django.forms import ModelForm
from django.core import validators
from second_app.models import User

class UserForm(ModelForm):
    class Meta:
        model = User
        fields = '__all__'
