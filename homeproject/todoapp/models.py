from django.db import models

# Create your models here.

class Todolist(models.Model):
    name = models.CharField(max_length=60)
    datetime = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return self.name

class Todoitem(models.Model):
    description = models.CharField(max_length=200)
    due_date=models.DateTimeField(null=True)
    completed=models.BooleanField()
    list= models.ForeignKey(Todolist,on_delete=models.CASCADE)

    def __str__(self):
        return self.description